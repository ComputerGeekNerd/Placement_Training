#Exact implementation of itertools combinations function

def combin(iterable, r):
    # combinations('ABCD', 2) --> AB AC AD BC BD CD
    # combinations(range(4), 3) --> 012 013 023 123
    pool = tuple(iterable)
    n = len(pool)
    if r > n:
        return
    indices = list(range(r))
    #yield tuple(pool[i] for i in indices)
    yield tuple((tuple(pool[i] for i in indices),tuple(indices))) #Returns the first set of combinations
    while True:
        for i in reversed(range(r)):
            if indices[i] != i + n - r:#the last combination will satisfy this and will return to main
                break
        else:
            return
        indices[i] += 1#the value which does satisfied the above condition is incremented and combinations starts from there 
        for j in range(i+1, r):
            indices[j] = indices[j-1] + 1
        #yield tuple(pool[i] for i in indices) #Returns tuple of combination elements
        yield tuple((tuple(pool[i] for i in indices),tuple(indices)))

arr = [int(x) for x in input("Enter array:").split()]
r = int(input("No. of combinations:"))
k = int(input("Enter sum:"))
com = combin(arr,r)
for i in com:
     if sum(i[0]) == k:
          print(i[0],end=':')
          print(i[1])