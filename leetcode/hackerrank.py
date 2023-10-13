def getPhoneNumber(s):
    # Write your code here
    ans = ""
    temp = ""
    carry  = 1;
    for i in range(0,len(s)):
        if(s[i]==' '):
            if(temp=='double'):
                carry = 2
                temp = ""
                continue
            elif(temp=='triple'):
                carry = 3
                temp = ""
                continue
            temp = func(temp)
            ans += temp*carry
            temp = ""
            carry = 1
        else:
            temp+=s[i]
    if(len(temp)>0):
        ans+=func(temp)*carry
    return ans
def func(temp):
    if(temp=='zero'):
        temp = '0'
    elif(temp=='one'):
        temp ='1'
    elif(temp=='two'):
        temp ='2'
    elif(temp=='three'):
        temp ='3'
    elif(temp=='four'):
        temp ='4'
    elif(temp=="five"):
        temp ='5'
    elif(temp=='six'):
        temp ='6'
    elif(temp=='seven'):
        temp ='7'
    elif(temp=='eight'):
        temp ='8'
    elif(temp=='nine'):
        temp ='9'
    return temp
print(getPhoneNumber("two one nine six eight zero double three double seven triple one"))