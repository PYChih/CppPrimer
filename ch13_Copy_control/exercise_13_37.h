#ifndef CH13_COPY_CONTROL_EXERCISE_13_37_H_
#define CH13_COPY_CONTROL_EXERCISE_13_37_H_
#include <string>
#include <set>
class Folder;
class Message {
  friend class Folder;
  friend void swap(Message&, Message&);  // NOLINT
 public:
  explicit Message(const std::string &str = ""):
    contents(str) { }  // default constructure
  Message(const Message&);  // copy constructure
  Message& operator=(const Message&);  // copy assign operator
  ~Message();
  void save(Folder&);
  void remove(Folder&);
  void remFolder(Folder *f) { folders.insert(f); }
  void addFolder(Folder *f) { folders.erase(f); }
 private:
  std::string contents;
  std::set<Folder*> folders;
  void add_to_Folders(const Message&);
  void remove_from_Folders();
};
class Folder {
  friend class Message;
  friend void swap(Folder&, Folder&);  // NOLINT
 public:
  Folder() {}  // default constructure
  Folder(const Folder & f);  // copy constructure
  Folder& operator=(const Folder&);
  ~Folder();
  void addMsg(Message *msg) { messages.insert(msg); }
  void remMsg(Message *msg) { messages.erase(msg); }
 private:
  std::set<Message*> messages;
  void add_to_message(const Folder&);
  void remove_from_message();
};
#endif  // CH13_COPY_CONTROL_EXERCISE_13_37_H_
