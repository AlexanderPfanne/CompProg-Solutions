import fileinput
from z3 import *

res = 0
for line in fileinput.input():
    words = line.split(' ')
    buttons = [list(map(int, ws[1:-1].split(','))) for ws in words[1:-1]]
    voltages = list(map(int, words[-1][1:-2].split(',')))

    opt = z3.Optimize()

    # Variables
    vs = [Int(f'v_{i}') for i in range(len(buttons))]
    for v in vs:
        opt.add(v >= 0)
    opt.minimize(sum(vs))

    # Constraints
    for i in range(len(voltages)):
        ts = []
        for j in range(len(buttons)):
            if i in buttons[j]:
                ts.append(vs[j])
        opt.add(sum(ts) == voltages[i])

    # Solve
    assert opt.check()
    for v in vs:
        res += opt.model()[v].as_long()
print(res)
