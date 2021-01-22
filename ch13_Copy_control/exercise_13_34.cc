// Exercise 13_34
// Write the Message class as described in this section.
#include <iostream>
#include "exercise_13_34.h"  //NOLINT

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
Message::Message(const Message& msg):
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
