# your code goes here
n = int(input())

if(n == 1):
	print("TAK")
		
else:
	while(n % 2 == 0 and n > 0):
		n /= 2
		if( n == 1 ):
			print("TAK")
			break
		
	if(n > 1):
		print("NIE")
