def enc(s):
	n = len(s)
	count = 0
	if (n == 0 or n == 1):
		return 1
	else:
		if (s[n-1] != '0'):
			count = enc(s[0:n-1])
			if(s[n-2] != '0' and int(s[n-2:n]) < 27):
				count += enc(s[0:n-2])
		else:
			if (s[n-2] != '0' and int(s[n-2:n]) < 27):
				count = enc(s[0:n-1])
		return count

s = input("Enter sequence: ")
if s[0] != '0':
	if '00' not in s:
		c = enc(s)
		if c>0:
			print(c)
		else:
			print('Invalid Case "X0"')
	else:
		print('Invalid case: 00 in sequence')
else:
	print('Invalid case: Leading 0')


	