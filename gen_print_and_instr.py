import re

# Deve fazer o mapeamento para usar no vetor de print, posteriormente
def array_function(prefix,list_tup, vetname='vet', includes=[]):
	vetname = str(vetname)
	st = ''
	for i in includes:
		st += '#include "{}"\n'.format(i)
	st+= "void ** {} ".format(vetname)+'{\n'
	st+= "  void** {};\n".format(vetname)
	st+= "  {} = (void**)malloc(1000 * sizeof(void*));\n".format(vetname)
	for i in range(len(list_tup[0])):
		name, ii = list_tup[0][i], list_tup[1][i]
		st += "  {}[{}] = {};\n".format(vetname, ii, prefix+name.strip())
	open(vetname+'.hpp', 'w').write(st)
	open(vetname+'.hpp', 'a').write("  return {};\n}}\n".format(vetname))
	return 0



def lazy_gen(filename, prefix):
	lines = [i.strip() for i in open(filename)]
	# print(lines)
	it = 0
	c = -1
	sign = 'void ' + prefix
	lis = []
	idx = []
	while it < len(lines)  :
		ln = lines[it]
		while re.findall('enum', ln):
			it += 1
			ln = lines[it]
		if re.findall('=', ln):
			# print('with equeal :: ', ln)
			# print(re.findall(r'([^\s]+).+?(\d+)', ln))
			c = int(re.findall(r'([^\s]+).+?(\d+)', ln)[0][1])
		else:
			c += 1
		
		idx.append(c)  # to do the array of pointers
		
		# print('c == ', str(c))
		lis.append(re.findall(r'([^\s]+)', ln)[0])
		it += 1
	with open(prefix+filename+'.hpp', 'w') as ff:
		for i in lis:
			ff.write(sign + i + ' {\n\n}\n')
	print('QTD :: ',len(lis))
	return [lis, idx]

def lazy_genp(filename, prefix):
	lines = [i.strip() for i in open(filename)]
	# print(lines)
	it = 0
	c = -1
	sign = 'void ' + prefix
	lis = []
	idx = []
	while it < len(lines)  :
		ln = lines[it]
		while re.findall('enum', ln):
			it += 1
			ln = lines[it]
		if re.findall('=', ln):
			# print('with equeal :: ', ln)
			# print(re.findall(r'([^\s]+).+?(\d+)', ln))
			c = int(re.findall(r'([^\s]+).+?(\d+)', ln)[0][1])
		else:
			c += 1
		
		idx.append(c)  # to do the array of pointers
		
		# print('c == ', str(c))
		lis.append(re.findall(r'([^\s]+)', ln)[0])
		it += 1
	with open(prefix+filename+'.hpp', 'w') as ff:
		for i in lis:
			ff.write(sign + i + ' {\n\tstd::cout << "' + i[4:100] + '";\n}\n')
	print('QTD :: ',len(lis))
	return [lis, idx]

def main():
	array_function('exec_', lazy_gen('instr', 'exec_'), vetname='exec_vet')
	array_function('print_', lazy_genp('instr', 'print_'), vetname='print_vet')
	return 0
if __name__ == '__main__':
	main()