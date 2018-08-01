package leetcode

import (
	"testing"
)

func TestShiftingLetters(t *testing.T) {
	t.Logf("u shift 17: %c", 'u' + (17 % 26) - 'z' + 'a')

	res := shiftingLetters("abc", []int{3, 5, 9})
	if res != "rpl" {
		t.Error(res)
	}

	res = shiftingLetters("ruu", []int{26, 9, 17})
	if res != "rul" {
		t.Error(res)
	}

	res = shiftingLetters("z", []int{52})
	if res != "z" {
		t.Error(res)
	}
}
