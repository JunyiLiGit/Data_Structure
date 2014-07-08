a = [[7,9,3,4,8,4],[8,5,6,4,5,7]]


t = [[2,3,1,3,4,3],[2,1,2,2,1,2]]

e = [2,4]

x = [3,2]

def fastest_way (a, t, e, x, n):
    costOne = []
    costTwo = []
    lineOne = []
    lineTwo = []
    #caculate f1[0] and f2[0]
    costOne.append(e[0] + a[0][0])
    costTwo.append(e[1] + a[1][0])
    for j in range(1,n):
      if costOne[j - 1] + a[0][j] <= costTwo[j - 1] + t[1][j-1] + a[0][j]:
        costOne.append(costOne[j-1] + a[0][j])
        lineOne.append(0)
      else:
        costOne.append(costTwo[j-1] + t[1][j-1] + a[0][j])
        lineOne.append(1)
      if costTwo[j - 1] + a[1][j] <= costOne[j - 1] + t[0][j-1] + a[1][j]:
        costTwo.append(costTwo[j-1] + a[1][j])
        lineTwo.append(1)
      else:
        costTwo.append(costOne[j-1] + t[0][j-1] + a[1][j])
        lineTwo.append(0)

    if costOne[n-1] + x[0] <= costTwo[n-1] + x[1]:
      totalCost = costOne[n-1] + x[0]
      startLine = 0
    else:
      totalCost = costTwo[n-1] + x[1]
      startLIne = 1

    cost = [costOne,costTwo]
    line = [lineOne,lineTwo]
    print "cost table is " + str(cost)
    print "line table is " + str(line)
    print "start line is " + str(startLine)



    results = {
    "costTable" : cost,
    "lineTable" : line,
    "totalCost" : totalCost,
    "startLine" : startLine
    }
    return results

def print_stations(line, startLine, stationNumber):
    i = startLine
    print "line " + str(i) + " station " + str(stationNumber-1)
    for j in range(stationNumber-2,-1,-1):
      i = line[i][j]
      print "line " + str(i) + " station " + str(j)


results = fastest_way(a,t,e,x,6)
print_stations(results['lineTable'], results['startLine'], 6)
