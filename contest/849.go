package leetcode

func maxDistToClosest(seats []int) int {
	maxDist := 0    
	curDist := 0
	for _, x := range seats {
		if x == 0 {
			curDist++
		} else {
			if maxDist < curDist {
				maxDist = curDist
			}
			curDist = 0
		}
	}
	maxDist = (maxDist - 1) / 2 + 1

	// left empty
	curDist = 0
	for i := 0; seats[i] == 0; i++ {
		curDist++
	}
	if maxDist < curDist {
		maxDist = curDist
	}

	// right empty
	curDist = 0
	for i := len(seats) - 1; seats[i] == 0; i-- {
		curDist++
	}
	if maxDist < curDist {
		maxDist = curDist
	}

	return maxDist
}
