# your code goes here
t = int(input())

while(t != -1):
	v = 0
	sm = 0
	l = []
	for i in range(t):
		a = int(input())
		sm += a
		l.append(a)
	
	if((sm % t) != 0):
		y = -1
	
	else:
		for i in range(t):
			v += abs(( sm // t ) - l[i])
			y = v//2
	
	print(y)
	t = int(input())
		
