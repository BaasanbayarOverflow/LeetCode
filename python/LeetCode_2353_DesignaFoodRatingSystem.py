from collections import defaultdict

x = defaultdict(dict)
x['letter']['a'] = 1
x['word']['b'] = 2
x['letter']['c'] = 3

for k, v in x.items():
    print(k, v)