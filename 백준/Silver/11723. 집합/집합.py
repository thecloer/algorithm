import sys

if __name__ == '__main__':
    readline = sys.stdin.readline
    INIT_SET = 1
    for i in range(20):
        INIT_SET = (INIT_SET << 1) + 1
    M = int(readline())
    s = 0
    while M > 0:
        M -= 1
        cmd = readline().rstrip()
        if cmd == 'all':
            s=INIT_SET
        elif cmd == 'empty':
            s = 0
        else:
            cmd, n = cmd.split()
            x = 1 << (int(n) - 1)
            if cmd == 'add':
                s |= x
            elif cmd == 'remove':
                s &= ~x
            elif cmd == 'toggle':
                s ^= x
            elif cmd == 'check':
                print(1 if (s & x) else 0)