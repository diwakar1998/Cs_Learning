import array as arr

nums=[-3,-3,-1,0,0,1,1,5,5,6]

temp=[]
for each in nums:
    if(each in temp):
        continue
    temp.append(each)
    print(temp)
    

print(temp)