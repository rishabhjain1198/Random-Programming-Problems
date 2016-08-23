import bisect

#Time to take input
tempenvelopes = []
dp = []
inputting = 1
while(inputting):
    print("Please enter values for envelopes %2d" % (inputting))
    tempenvelopes.append(input().split(" "))
    print("Press 0 to exit or any other number to continue entering values")
    if input() == '0':
        inputting = 0
    else:
        inputting += 1
envelopes=[[int(y) for y in x] for x in tempenvelopes]
#input done

envelopes.sort(key = lambda x: (x[0], -x[1]))
for x in envelopes:
    i = bisect.bisect_left(dp, x[1])
    if i == len(dp):
        dp.append(x[1])
    else:
        dp[i] = x[1]
print("Maximum dolls which can be Russian Dolled is: %d"%(len(dp)))
