
def rev(s):
	s1 = ''
	l = len(s)
	return ''.join([ s[l - k - 2] + s[l - k - 1] for k in range(0, l, 2)])
