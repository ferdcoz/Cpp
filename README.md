# C++ / Personal Libraries

# APIs

## Arrays
## add
**Prototype:**
```cpp 
int add(T arr[],int& len,T e);
```
**Description:** insert element `e` at the end of `arr`, increasing its length `len` +1.

**Parameters:**
- `T arr[ ]` – This is the array where the element `e` will be added.
- `int& len` – Current array length.
- `T e` – This is the element `e` which will be added to the array.

**Returns:** `int` -  Position where the element `e` has been placed.

**Sample code:**
```cpp
// array creation and lenght initialization
string a[10]; 
int len = 0; 

// add elements to the array
add<string>(a,len,"John"); 
add<string>(a,len,"Paul"); 
add<string>(a,len,"George"); 
add<string>(a,len,"Ringo"); 

// print array elements 
for(int i=0;i<len;i++) 
{ 
	cout << a[i] << endl; 
}
```
--------------
## insert

**Prototype:**
```cpp 
void insert(T arr[],int& len,T e,int p);
```
**Description:** inserts element `e` at position `p` of `arr`. It displace the elements starting from `p+1` and also increases `len` +1.

**Parameters:**
- `T arr[ ]` – This is the array where the element `e` will be inserted.
- `int& len` – Current array length.
- `T e` – This is the element `e` which will be added to the array.
- `int p` - Array position `p` where the new element will be inserted.

**Returns:** `void` 

**Sample code:**
```cpp
// array creation and lenght initialization
string a[10]; 
int len = 0; 

// add elements to the array 
insert<string>(a,len,"John",0); 
insert<string>(a,len,"Paul",0); 
insert<string>(a,len,"George",0); 
insert<string>(a,len,"Ringo",0); 

// print array elements
for(int i=0;i<len;i++) 
{ 
	// OUTPUT: Ringo,George,Paul,John
	cout << a[i] << endl;  
}
```

--------------
## remove
**Prototype:**
```cpp 
T remove(T arr[],int& len,int p);
```
**Description:** removes the  element at position `p` of `arr` array. It displace the elements starting from `p` and also decreases `len` -1.

**Parameters:**
- `T arr[ ]` – This is the array where the element `e` will be removed.
- `int& len` – Current array length.
- `T p` – Array position `p` from where the element will be removed.

**Returns:** `T` - element which has been removed from array. 

**Sample code:**
```cpp
// array creation and lenght initialization 
string a[10]; 
int len = 0; 

// add elements to the array 
add<string>(a,len,"John"); 
add<string>(a,len,"Paul"); 
add<string>(a,len,"George"); 
add<string>(a,len,"Ringo");

// print array elements
while( len>0 ) 
{ 
	// OUTPUT: John, Paul, George, Ringo
	cout << remove<string>(arr,len,0) << endl; 
}
```
--------------
### insert
Description:

--------------
### orderedInsert
Description:

--------------
### sort
Description:

--------------
### binarySearch
Description:

--------------
### heapSort
Description:

--------------
### radixSort
Description:
