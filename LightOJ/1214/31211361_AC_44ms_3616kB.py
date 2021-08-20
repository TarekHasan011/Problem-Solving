t=input()
for i in range(int(t)):
    dummy = input().split()
    if int(dummy[0])%int(dummy[1])==0:
        print(f"Case {i+1}: divisible")
    else:
        print(f"Case {i+1}: not divisible")