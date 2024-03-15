bots = [[0.5, 0.5], [0.3, 0.5], [0.2, 0.4]]

def EV(x, y):
    return x + y

def dfs(d, path, value):
    if (d == 4):
        print(value, ": ", path)
        return

    for i in range(3):
        tmp = path
        tmp.append(i)
        dfs(d + 1, tmp, value + EV(bots[i][0], bots[i][1]))

path = []
dfs(0, path, 0)
