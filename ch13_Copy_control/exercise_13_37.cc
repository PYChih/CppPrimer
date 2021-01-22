// Exercise 13_37
//  Add members to the Message class to insert
//  or remove a given Folder* into folders.
//  These members are analogous to Folder’s addMsg and remMsg operations.
#include <iostream>
#include "exercise_13_37.h"  //NOLINT

void Folder::add_to_message(const Folder &f) {
  for (auto m : f.messages) {
      m->addFolder(this);
  }
}
void Folder::remove_from_message() {
  for (auto m : messages) {
    m->remFolder(this);
  }
}

Folder::Folder(const Folder &f) :
  messages(f.messages) {
    add_to_message(f);
}
Folder::~Folder() {
    remove_from_message();
}
Folder& Folder::operator=(const Folder &f) {
    remove_from_message();
    messages = f.messages;
    add_to_message(f);
    return *this;
}

void Message::save(Folder &f) {
  folders.insert(&f);
  f.addMsg(this);
}
void Message::remove(Folder &f) {
  folders.erase(&f);
  f.remMsg(this);
}
void Message::add_to_Folders(const Message& msg) {
  for (auto f : msg.folders) {
      f->addMsg(this);
  }
}
Message::Message(const Message& msg) :
  contents(msg.contents), folders(msg.folders) {
      add_to_Folders(msg);
  }
void Message::remove_from_Folders() {
  for (auto f : folders) {
    f->remMsg(this);
  }
  folders.clear();
}
Message::~Message() {
  remove_from_Folders();
}
Message& Message::operator=(const Message &msg) {
  remove_from_Folders();
  contents = msg.contents;
  folders = msg.folders;
  add_to_Folders(msg);
  return *this;
}
void swap(Message& m1, Message& m2) {
  using std::swap;
  for (auto f : m1.folders) {
    f->remMsg(&m1);
  }
  for (auto f : m2.folders) {
    f->remMsg(&m2);
  }
  swap(m1.folders, m2.folders);
  swap(m1.contents, m2.contents);
  for (auto f : m1.folders) {
    f->addMsg(&m1);
  }
  for (auto f : m2.folders) {
    f->addMsg(&m2);
  }
}
void swap(Folder &f1, Folder &f2) {
    using std::swap;
    for (auto m : f1.messages) {
        m->remFolder(&f1);
    for (auto m : f2.messages) {
        m->remFolder(&f2);
    }
    swap(f1.messages, f2.messages);
    for (auto m : f1.messages) {
        m->addFolder(&f1);
    }
    for (auto m : f2.messages) {
        m->addFolder(&f2);
    }
    }
}
int main() {
    Message m1;
    Folder f1;
}
