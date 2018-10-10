import re

# f = open(input('Digite o nome do arquivo'), 'r')
fi = input('the name of the header to have the fill_from produced to\n')
fi = re.sub('.hpp', '', fi)
f = open(fi + '.hpp', 'r')

li = [i for i in f]

sli = len(li)
i = 0
lis = []
while i < sli:
  if re.findall('class', li[i]) and not re.findall('(}|^enum)', li[i]) and re.findall('public:', li[i]):    
    l = li[i][0:-1]
    l = re.sub('class', 'void', l)
    l = re.sub('{public:', ' :: fill_from(FILE * f) {', l)
    # print(l)
    i += 1
    while i < sli and not re.findall('{', li[i]):
      # print('l ==> ', li[i])
      tmp = re.findall('^.+ (.+) *;', li[i])
      # print('HERE',tmp)
      if tmp:
        tmp = tmp[0]
        l = l + '\n\tread_us(&'+tmp+', sizeof('+tmp+'), f);'
      i += 1
    l += '\n}\n\n'
    lis.append(l)
    # print(l)
  i += 1
lis = ['#pragma once\n#include <stdio.h>', '\n#include "'+fi+'.hpp"\n\n'] + lis
with open(fi+'.cpp', 'w') as ff:
  for i in lis:
    ff.write(i)