path = '2.txt'

with open(path) as f:
    lines = f.readlines()

print(lines)
# ['XXX YYY ZZZ\n', 'YYY\n', 'aaa\n', 'XXX\n', 'ZZZ XXX\n', 'xxx']

print(type(lines))
# <class 'list'>

lines_strip = [line.strip() for line in lines]
print(lines_strip)
# ['XXX YYY ZZZ', 'YYY', 'aaa', 'XXX', 'ZZZ XXX', 'xxx']
l_XXX = [line for line in lines_strip if 'XXX' in line]
print(l_XXX)
# ['XXX YYY ZZZ', 'XXX', 'ZZZ XXX']
for line in l_XXX:
    print(line)
# XXX YYY ZZZ
# XXX
# ZZZ XXX
l_XXX_start = [line for line in lines_strip if line.startswith('XXX')]
print(l_XXX_start)
# ['XXX YYY ZZZ', 'XXX']