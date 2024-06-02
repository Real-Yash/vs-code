def genrate (n):
    import random
    l=[]
    for i in range (n):
     l.append(random.randint(1,50))
    return l
   
n=(input('enter the random value to see magic:\n'))
print("the random list  is:", genrate(n) ) 

'''
l=[]
    for i in range(5):
     l.append(random.randint(1, 50))
     print("Original list:",l)

print("\n After sorting the list using bubble sort algorithm")
bubble_sort(l)
print("Sorted List:",l)
l.sort
print(l)
'''