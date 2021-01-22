#Exercise 13_33
> Why is the parameter to the save and remove members of Message a Folder&? Why didn’t we define that parameter as Folder? Or const Folder&?
    - 因為save和remove會改變folder，所以要馬傳指標要馬傳參考，而且不能是const