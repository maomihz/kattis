from sys import stdin

def evaluate(groups, words):
    oplist = {
        'union': lambda x, y: x | y,
        'intersection': lambda x, y: x & y,
        'difference': lambda x, y: x - y
    }
    
    items = list()
    
    for w in reversed(words):
        if w in oplist:
            a = items.pop()
            b = items.pop()
            items.append(oplist[w](a, b))
        else:
            items.append(groups[w])
    return items.pop()
        

groups = dict()
for line in stdin:
    words = line.split()
    op = words[0]
    if op == 'group':
        name = words[1]
        groups[name] = set(words[3:])
    else:
        print(' '.join(sorted(list(evaluate(groups, words)))))

