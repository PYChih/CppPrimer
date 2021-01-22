#ifndef CH13_COPY_CONTROL_EXERCISE_13_34_H_
#define CH13_COPY_CONTROL_EXERCISE_13_34_H_
#include <string>
#include <set>
class Folder;
class Message {
  friend class Folder;
  friend void swap(Message&, Message&);
 public:
  explicit Message(const std::string &str = ""):
    contents(str) { }  // default constructure
  Message(const Message&);  // copy constructure
  Message& operator=(const Message&);  // copy assign operator
  ~Message();
  void save(Folder&);
  void remove(Folder&);
 private:
  std::string contents;
  std::set<Folder*> folders;
  void add_to_Folders(const Message&);
  void remove_from_Folders();
};
#endif  // CH13_COPY_CONTROL_EXERCISE_13_34_H_
