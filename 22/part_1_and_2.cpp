from sys import stdin

class box():
    def __init__(self, x, x1, y, y1, z, z1, state):
        self.x = x
        self.x1 = x1
        self.y = y
        self.y1 = y1
        self.z = z
        self.z1 = z1
        self.state = state
    
    def vol(self):
        return (self.x1 - self.x+1) * (self.y1 - self.y+1) * (self.z1 - self.z+1)

    def __str__(self):
        return str(self.x) + ' ' + str(self.x1) + ' ' + str(self.y) + ' ' + str(self.y1) + ' ' + str(self.z) + ' ' + str(self.z1)

    def intersect(self, other):
        if (other.x1 < self.x):
            return [self]
        if (other.x > self.x1):
            return [self]
        if (other.y1 < self.y):
            return [self]
        if (other.y > self.y1):
            return [self]
        if (other.z1 < self.z):
            return [self]
        if (other.z > self.z1):
            return [self]
        if (self.x >= other.x and self.x1 <= other.x1 and self.y >= other.y and self.y1 <= other.y1 and self.z >= other.z and self.z1 <= other.z1):
            return []

        xs, ys, zs = [], [], []

        if (self.x >= other.x and self.x1 <= other.x1):
            xs.append((self.x, self.x1))
            
        elif (self.x <= other.x and self.x1 >= other.x1):
            xs.append((other.x, other.x1))
            if (other.x - 1 - self.x >= 0):
                xs.append((self.x, other.x - 1))
            if (self.x1 - other.x1 - 1 >= 0):
                xs.append((other.x1+1, self.x1))

        elif (self.x <= other.x and self.x1 <= other.x1):
            if (other.x - 1 - self.x >= 0):
                xs.append((self.x, other.x - 1))
            if (self.x1 - other.x >= 0):
                xs.append((other.x, self.x1))

        elif (self.x >= other.x and self.x1 >= other.x1):
            if (other.x1 - self.x >= 0):
                xs.append((self.x, other.x1))
            if (self.x1 - other.x1 -1>= 0):
                xs.append((other.x1+1, self.x1))

        if (self.y >= other.y and self.y1 <= other.y1):
            ys.append((self.y, self.y1))
            
        elif (self.y <= other.y and self.y1 >= other.y1):
            ys.append((other.y, other.y1))
            if (other.y - 1 - self.y >= 0):
                ys.append((self.y, other.y - 1))
            if (self.y1 - other.y1 - 1 >= 0):
                ys.append((other.y1+1, self.y1))

        elif (self.y <= other.y and self.y1 <= other.y1):
            if (other.y - 1 - self.y >= 0):
                ys.append((self.y, other.y-1))
            if (self.y1 - other.y >= 0):
                ys.append((other.y, self.y1))

        elif (self.y >= other.y and self.y1 >= other.y1):
            if (other.y1 - self.y >= 0):
                ys.append((self.y, other.y1))
            if (self.y1 - other.y1 -1>= 0):
                ys.append((other.y1+1, self.y1))

        if (self.z >= other.z and self.z1 <= other.z1):
            zs.append((self.z, self.z1))
            
        elif (self.z <= other.z and self.z1 >= other.z1):
            zs.append((other.z, other.z1))
            if (other.z - 1 - self.z >= 0):
                zs.append((self.z, other.z - 1))
            if (self.z1 - other.z1 - 1 >= 0):
                zs.append((other.z1+1, self.z1))

        elif (self.z <= other.z and self.z1 <= other.z1):
            if (other.z -1- self.z >= 0):
                zs.append((self.z, other.z-1))
            if (self.z1 - other.z >= 0):
                zs.append((other.z, self.z1))

        elif (self.z >= other.z and self.z1 >= other.z1):
            if (other.z1 - self.z >= 0):
                zs.append((self.z, other.z1))
            if (self.z1 - other.z1 -1>= 0):
                zs.append((other.z1+1, self.z1))

        boxes1 = []
        for x in xs:
            for y in ys:
                for z in zs:
                    if (x[0] >= other.x and x[1] <= other.x1 and y[0] >= other.y and y[1] <= other.y1 and z[0] >= other.z and z[1] <= other.z1):
                        continue
                    else:
                        boxes1.append(box(x[0], x[1], y[0], y[1], z[0], z[1], self.state))
        
        return boxes1

from collections import deque 
boxes = deque()

for line in stdin:
    state = (line.split(' ')[0] == 'on')
    coords = line.split(' ')[1].split(',')
    x = int(coords[0].split('=')[1].split('..')[0])
    x1 = int(coords[0].split('=')[1].split('..')[1])
    y = int(coords[1].split('=')[1].split('..')[0])
    y1 = int(coords[1].split('=')[1].split('..')[1])
    z = int(coords[2].split('=')[1].split('..')[0])
    z1 = int(coords[2].split('=')[1].split('..')[1])

    boxes.append(box(x, x1, y, y1, z, z1, state))

ans = deque()
checker = deque()
while(len(boxes) > 0):
    cur1 = boxes.pop()
    queue = deque([cur1])
    if (cur1.state):
        while(len(queue) > 0):
            cur = queue.pop()
            yes = True
            for j in range(len(checker)):
                res = cur.intersect(checker[j])
                if (len(res) != 1):
                    s = str(cur)
                    for b in res:
                        queue.append(b)
                    yes = False
                    break
                elif (str(res[0]) != str(cur)):
                    queue.append(res[0])
                    yes = False
                    break
            if yes:
                ans.append(cur)
    checker.append(cur1)

vol = 0

for b in ans:
    if b.state:
        vol += b.vol()
print(vol)
