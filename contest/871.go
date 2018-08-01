package main

func nextRefuel(curDist int, stations [][]int) int {
	next := -1
	for i := range stations {
		if stations[i][0] > curDist || stations[i][1] == 0 {
			continue
		}
		if next == -1 {
			next = i
			continue
		}
		if stations[i][1] > stations[next][1] {
			next = i
		}
	}
	return next
}

func minRefuelStops(target int, startFuel int, stations [][]int) int {
	result := 0
	curDist := startFuel
	for curDist < target {
		next := nextRefuel(curDist, stations)
		if next == -1 {
			return -1
		}
		curDist = curDist + stations[next][1]
		stations[next][1] = 0
		result++
	}
	return result
}
