#!/usr/bin/env python
# coding: utf-8

# In[52]:


# IMPLEMENTATION OF BWT


s="localprocessingofcodeddataforlargescalestorage"
s=s+"$"
table=[]
length=len(s)
print(length)
i=0
for char in s:
    i+=1
    table.append(s[i-1:]+s[:i-1])
print(table)
print(len(table))
table=sorted(table)
print(table)
BWTlist=[]
for item in table:
    BWTlist.append(item[len(item)-1:])
print(BWTlist)
print(len(BWTlist))
BWT=""
for item in BWTlist:
    BWT=BWT+item
print(BWT)

    


# In[53]:


# REVERSE BWT

f=[]
for item in table:
    f.append(item[:1])
print(f)
count_alphabet=[]
alphabet="abcdefghijklmnopqrstuvwxyz"
for char in alphabet:
    count_alphabet.append(BWT.count(char))
print(count_alphabet)
reverse_BWT=""
def skip_row(char):
            for i in range(26):
                if char==alphabet[i]:
                    skip=sum(count_alphabet[:i])
                    print(skip)
                    return skip
def rank(nextrow,char):
    count=0
    for i in range(nextrow):
        if BWT[i]==char:
            count+=1
            
    return count
    
        
for i in range(len(BWT)-1):
    if i==0:
        reverse_BWT=reverse_BWT+BWT[i]
        char=reverse_BWT[i]
        nextrow=0+1+skip_row(char)
    else:
        
        reverse_BWT=reverse_BWT+BWT[nextrow]
        char=reverse_BWT[i]
        nextrow=1+skip_row(char)+rank(nextrow,char)
        if BWT[nextrow]=="$":
            break
        

print(reverse_BWT[::-1])
        
    


                    
   
    
    
    
    
    
    


# In[ ]:




