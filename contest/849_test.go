package leetcode

import (
	"testing"
)

func TestMaxDistToCloseat(t *testing.T) {
	res := maxDistToClosest([]int{0, 0, 1, 0, 0, 1})	
	if res != 2 {
		t.Error(res)
	}

	res = maxDistToClosest([]int{0, 0, 1, 0, 0, 0, 0, 0, 1})	
	if res != 3 {
		t.Error(res)
	}
}
