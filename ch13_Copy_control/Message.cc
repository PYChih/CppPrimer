#include <iostream>
#include <utility>
#include "Message.h"  //NOLINT

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
Folder::Folder(const Folder &f) :  // copy constructor
  messages(f.messages) {
  add_to_message(f);
}
Folder::~Folder() {
  remove_from_message();
}
void Folder::move_Messages(Folder *f) {
  messages = std::move(f->messages);
  for (auto m : messages) {
    m->remFolder(f);
    m->addFolder(this);
  }
  f->messages.clear();
}
Folder::Folder(Folder &&f) {
  move_Messages(&f);
}
Folder& Folder::operator=(Folder &&rhs) {
  if (this != &rhs) {
    remove_from_message();
    move_Messages(&rhs);
  }
  return *this;
}
Folder& Folder::operator=(const Folder &rhs) {  // copy assignment operator
  remove_from_message();
  messages = rhs.messages;
  add_to_message(rhs);
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
void Message::move_Folders(Message *m) {
  folders = std::move(m->folders);
  for (auto f : folders) {
      f->remMsg(m);
      f->addMsg(this);
  }
  m->folders.clear();
}

Message::Message(Message &&m): contents(std::move(m.contents)) {
  move_Folders(&m);
}
Message& Message::operator=(Message &&rhs) {
  if (this != &rhs) {
      remove_from_Folders();
      contents = std::move(rhs.contents);
      move_Folders(&rhs);
  }
  return *this;
}
Message::~Message() {
  remove_from_Folders();
}
Message& Message::operator=(const Message &rhs) {
  remove_from_Folders();
  contents = rhs.contents;
  folders = rhs.folders;
  add_to_Folders(rhs);
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
