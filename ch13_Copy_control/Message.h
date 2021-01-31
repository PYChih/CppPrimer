#ifndef MESSAGE_H_
#define MESSAGE_H_
#include <string>
#include <set>
class Folder;
class Message {
  friend class Folder;
  friend void swap(Message&, Message&);  // NOLINT
 public:
  explicit Message(const std::string &str = ""):
    contents(str) { }  // default constructor
  Message(const Message &m);  // copy constructor
  Message(Message &&m);
  Message& operator=(const Message &rhs);  // copy-assignment operator
  Message& operator=(Message &&rhs);
  ~Message();
  void save(Folder&);
  void remove(Folder&);
  void remFolder(Folder *f) { folders.erase(f); }
  void addFolder(Folder *f) { folders.insert(f); }
 private:
  std::string contents;
  std::set<Folder*> folders;
  void add_to_Folders(const Message&);
  void remove_from_Folders();
  void move_Folders(Message *m);
};
class Folder {
  friend class Message;
  friend void swap(Folder&, Folder&);  // NOLINT
 public:
  Folder() {}  // default constructor
  Folder(const Folder &f);  // copy constructor
  Folder& operator=(const Folder &rhs);  // copy-assignment operator
  Folder(Folder &&f);
  Folder& operator=(Folder &&rhs);
  ~Folder();
  void addMsg(Message *msg) { messages.insert(msg); }
  void remMsg(Message *msg) { messages.erase(msg); }
 private:
  std::set<Message*> messages;
  void add_to_message(const Folder&);
  void remove_from_message();
  void move_Messages(Folder *f);
};
#endif  // MESSAGE_H_
