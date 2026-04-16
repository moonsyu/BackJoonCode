from sys import *
#import time

def main():
    zero = [1, 0]
    one = [0, 1]

    #start = time.time()

    t = int(stdin.readline())

    for i in range(t):
        n = int(stdin.readline())

        size = len(zero)
        for j in range(size, n + 1):
            zero.append(zero[j - 1] + zero[j - 2])
            one.append(one[j - 1] + one[j - 2])
            #stdout.write(f'{j} {zero[j]} {one[j]}\n')
        stdout.write(f'{zero[n]} {one[n]}\n')

    #end = time.time()

    #stdout.write(f'{end - start}')
if __name__ =="__main__":
    main()