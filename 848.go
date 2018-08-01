package leetcode

func shiftingLetters(S string, shifts []int) string {
	for i := len(shifts) - 2; i >= 0; i-- {
		shifts[i] = (shifts[i] + shifts[i+1]) % 26
	}
	out := []byte(S)
	for i := range out {
		out[i] = 'a' + byte((int(out[i] - 'a') + shifts[i]) % 26)
	}
	return string(out)
}
