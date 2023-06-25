/*Problem:
dictionary of words present in book. This dictionary will have page number list for each words.

vector<string,list<int>> == {{"Brutus","1,4,7,19,34"},{"caeser",3,4,8,9,45},{},};


question 1 -- > What are pages where both brutus and ceaser are present?

If two sorted array is given find out common element or intersection of two sorted arrays.


ans 1 ->put first sorted in hashset and then search by takining element from first list..it will be

T: o(n) + o(n)

ans 2 -> using two pointer technique..o(n+m).

ans 3 -> take i from list 1 and binary search in list 2. it will be mlogn.

which is better ? ans2 or ans3?
if size of list are similar then better to go for 2 pointer approach.
if size of list are very different from each other...one is very big and another is very small
binary search will be better..binary search should be applied on bigger array.

question 2 --> Union of two sorted list: use 2 pointer tech...
logic very same to merge sort....only duplicate number will be avoided..

question 3: how to intersection of n sorted list...? each lenghth of each list is k.

ans 0: Frequency count solution....
       count the frequency of each   number...
       which frequency is most common and then we can search in hash set...
       map<pageNum,frequency>

ans 1: using hash set. adding all array numbers in a temp hash set for first list,
       then go thorugh 2nd list and add all numbers which are present in temp hash set to another hash
       set and discard previus temp hash set. Make this hash set as new temp hash set.
       then go to the third list and add all numbers present in new hash set to another new hash set and
       discard temp hash set.
       n*k  and inserting and finding in hash set is o(1).



ans 2: using k pointers...
       if(k1==k2==....==kn) res.add(k1), increment all k1.
       else increment_smallest_of_key(k1,k2,...kn)
      n*k


*/
