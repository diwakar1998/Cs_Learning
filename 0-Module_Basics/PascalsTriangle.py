from inspect import trace
from pip import main


def triangle(numRows):
    ans=[]
    for i in range(1,numRows+1):
        temp=[]
        for j in range(1,i+1):
            if(j==1 or j==i):
                temp.append(1)
            else:
                temp.append(ans[i-2][j-2]+ans[i-2][j-1])
                # print(temp)
        ans.append(temp)
    return ans
    


if __name__ == '__main__':
    ans=triangle(5)
    for each in ans:
        print(each)