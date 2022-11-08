import sys;input = sys.stdin.readline
N = int(input())
check_plate = [0] * 1000001
count = 0

for p in range(N):
    plate = list(map(int,input().split()))
    if check_plate[plate[0]] != 1 and check_plate[plate[1]] != 1 and check_plate[plate[2]] != 1:
        count += 1
    check_plate[plate[0]] = 1
    check_plate[plate[1]] = 1
    check_plate[plate[2]] = 1

print(count)