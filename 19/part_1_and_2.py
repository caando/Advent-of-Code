permutations = [0, 1, 2], [0, 2, 1], [1, 0, 2], [1, 2, 0], [2, 0, 1], [2, 1, 0]

def check(a, b):
    ans = []
    index = 0
    for perm in permutations:
        if (abs(a[0]) == abs(b[perm[0]]) and abs(a[1]) == abs(b[perm[1]]) and abs(a[2]) == abs(b[perm[2]])):
            res = 0
            if (a[0] == -b[0]):
                res += 1
            if (a[1] == -b[1]):
                res += 2
            if (a[2] == -b[2]):
                res += 4
            ans.append((res, index))
        index+=1
    return ans

scanners = []
t = 0

with open("input.txt") as rf:
    header = rf.readline()
    while (header.strip() != ''):
        arr = []
        line = rf.readline()
        while(line.strip() != ''):
            line = line.strip().split(',')
            line[0] = int(line[0])
            line[1] = int(line[1])
            line[2] = int(line[2])
            arr.append(tuple(line))
            line = rf.readline()
        scanners.append(arr)
        header = rf.readline()
        t += len(arr)

diffs = []
for scanner in scanners:
    diff = {}
    for i in range(len(scanner)):
        for j in range(i+1, len(scanner)):
            if (i != j):
                diff[(i, j)] = [scanner[i][0] - scanner[j][0], scanner[i][1] - scanner[j][1], scanner[i][2] - scanner[j][2]]
    diffs.append(diff)

visited = [0] * len(scanners)
queue = [0]

loca = []
beacons = set()
for beacon in scanners[0]:
    beacons.add(beacon)

while(len(queue) > 0):
    i = queue.pop(0)
    if (not visited[i]):
        print(i)
        visited[i] = True
        for j in range(0, len(scanners)):
            if (not visited[j]):
                if (i!=j):
                    lst = [0]*6
                    cnt = {}
                    for k, diff1 in diffs[i].items():
                        if (tuple(scanners[i][k[0]])) not in cnt:
                            cnt[tuple(scanners[i][k[0]])] = {}
                        if (tuple(scanners[i][k[1]])) not in cnt:
                            cnt[tuple(scanners[i][k[1]])] = {}

                        for l, diff2 in diffs[j].items():
                            if abs(diff1[0]) + abs(diff1[1]) + abs(diff1[2]) == abs(diff2[0]) + abs(diff2[1]) + abs(diff2[2]):
                                res = check(diff1,diff2)
                                if res != []:
                                    for ori, rot in res:
                                        lst[rot] += 1
                                    if tuple(scanners[j][l[0]]) not in cnt[tuple(scanners[i][k[0]])]:
                                        cnt[tuple(scanners[i][k[0]])][tuple(scanners[j][l[0]])] = 0
                                    cnt[tuple(scanners[i][k[0]])][tuple(scanners[j][l[0]])] += 1
                                    if tuple(scanners[j][l[1]]) not in cnt[tuple(scanners[i][k[1]])]:
                                        cnt[tuple(scanners[i][k[1]])][tuple(scanners[j][l[1]])] = 0
                                    cnt[tuple(scanners[i][k[1]])][tuple(scanners[j][l[1]])] += 1
                                    if tuple(scanners[j][l[1]]) not in cnt[tuple(scanners[i][k[0]])]:
                                        cnt[tuple(scanners[i][k[0]])][tuple(scanners[j][l[1]])] = 0
                                    cnt[tuple(scanners[i][k[0]])][tuple(scanners[j][l[1]])] += 1

                                    if tuple(scanners[j][l[0]]) not in cnt[tuple(scanners[i][k[1]])]:
                                        cnt[tuple(scanners[i][k[1]])][tuple(scanners[j][l[0]])] = 0
                                    cnt[tuple(scanners[i][k[1]])][tuple(scanners[j][l[0]])] += 1
                    if (max(lst) >= 66):
                        matching = []

                        for x, y in cnt.items():
                            for y, z in y.items():
                                if (z > 1):
                                    matching.append((x, y))

                        temp, rot = check(
                            [matching[1][0][0] - matching[0][0][0],
                            matching[1][0][1] - matching[0][0][1],
                            matching[1][0][2] - matching[0][0][2]] ,
                            [matching[1][1][0] - matching[0][1][0],
                            matching[1][1][1] - matching[0][1][1],
                            matching[1][1][2] - matching[0][1][2]] ,
                        )[0]
                            
                        orient, temp = check(
                            [matching[1][0][0] - matching[0][0][0],
                            matching[1][0][1] - matching[0][0][1],
                            matching[1][0][2] - matching[0][0][2]] ,
                            [matching[1][1][permutations[rot][0]] - matching[0][1][permutations[rot][0]],
                            matching[1][1][permutations[rot][1]] - matching[0][1][permutations[rot][1]],
                            matching[1][1][permutations[rot][2]] - matching[0][1][permutations[rot][2]]] ,
                        )[0]

                        tx, ty, tz = 0, 0, 0
                        a, b, c = 1, 1, 1

                        if (orient & 1):
                            a = -1
                        if (orient & 2):
                            b = -1
                        if (orient & 4):
                            c = -1

                        tx = matching[0][0][0] - a * matching[0][1][permutations[rot][0]]
                        ty = matching[0][0][1] - b * matching[0][1][permutations[rot][1]]
                        tz = matching[0][0][2] - c * matching[0][1][permutations[rot][2]]
                        loca.append((tx, ty, tz))
                        
                        new_j = []

                        for i1 in range(len(scanners[j])):
                            x = tx + a * scanners[j][i1][permutations[rot][0]]
                            y = ty + b * scanners[j][i1][permutations[rot][1]]
                            z = tz + c * scanners[j][i1][permutations[rot][2]]
                            new_j.append((x, y, z))
                            beacons.add((x, y, z))
            
                        scanners[j] = new_j

                        diff = {}
                        for i1 in range(len(scanners[j])):
                            for j1 in range(i1+1, len(scanners[j])):
                                if (i1 != j1):
                                    diff[(i1, j1)] = [scanners[j][i1][0] - scanners[j][j1][0], scanners[j][i1][1] - scanners[j][j1][1], scanners[j][i1][2] - scanners[j][j1][2]]
                        diffs[j] = diff
                        queue.append(j)

high = 0
for i in range(len(loca)):
    for j in range(len(loca)):
        if abs(loca[i][0] - loca[j][0]) + abs(loca[i][1] - loca[j][1]) + abs(loca[i][2] - loca[j][2]) > high:
            high = abs(loca[i][0] - loca[j][0]) + abs(loca[i][1] - loca[j][1]) + abs(loca[i][2] - loca[j][2])
print(len(beacons), high)
