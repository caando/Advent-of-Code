from sys import stdin
from copy import deepcopy

def process(arr, depth):
    if (type(arr) == list):
        res = []
        for i in range(len(arr)):
            res += process(arr[i], depth+1)
        return res
    else:
        return [[arr, depth]]

def add(a, b):
    a = deepcopy(a)
    b = deepcopy(b)
    arr = a + b
    for i in range(len(arr)):
        arr[i][1] += 1
    reduce = True
    while(reduce):
        reduce = False
        exploded = False
        next = [arr[0]]
        for i in range(1, len(arr)):
            cur = arr[i]
            while (next[len(next)-1][1] == cur[1] and cur[1] > 4):
                if (len(next) > 1):
                    next[len(next)-2][0] += next[len(next)-1][0]
                if (len(arr) != i + 1):
                    arr[i+1][0] += cur[0]
                next.pop()
                cur = [0, cur[1]-1]
                if (len(next) == 0):
                    break
            next.append(cur)
        arr = next
        if (not exploded):
            next = []
            for i in range(len(arr)):
                if (arr[i][0] >= 10 and not exploded):
                    next.append([arr[i][0]//2, arr[i][1]+1])
                    next.append([arr[i][0]//2 + arr[i][0] % 2, arr[i][1]+1])
                    reduce = True
                    exploded = True
                else:
                    next.append(arr[i])
            arr = next
    return arr

def get_score(arr):
    stack = [arr[0]]
    for i in range(1, len(arr)):
        cur = arr[i]
        while (stack[len(stack)-1][1] == cur[1]):
            cur = [stack[len(stack)-1][0] *  3 + cur[0] * 2,cur[1]-1]
            stack.pop()
            if (len(stack) == 0):
                break
        stack.append(cur)
    return stack[0][0]

line = stdin.readline()

snailfishes = []

while(line):
    arr = eval(line)
    line = stdin.readline()
    snailfishes.append(process(arr, 0))

cur = snailfishes[0]
for i in range(1, len(snailfishes)):
    cur = add(cur, snailfishes[i])

high = 0

for i in range(len(snailfishes)):
    for j in range(len(snailfishes)):
        if (i != j):
            score = get_score(add(snailfishes[i], snailfishes[j]))
            high = max(high, score)

print(get_score(cur), high)
