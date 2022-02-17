from inspect import trace
from pip import main


def triangle(numRows):
    ans=[]
    for i in range(0,numRows):
        temp=[]
        for j in range(0,i+1):
            if(j==0 or j==i):
                temp.append(1)
            else:
                temp.append(ans[i-1][j-1]+ans[i-1][j])
                # print(temp)
        ans.append(temp)
    return ans
    


if __name__ == '__main__':
    ans=triangle(5)
    for each in ans:
        print(each)