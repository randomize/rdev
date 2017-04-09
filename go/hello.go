package main

import (
	"fmt"
	"math"
	"math/big"
	"math/cmplx"
	"math/rand"
	"runtime"
	"time"
)

/// boo
func name() {

	fmt.Println("Number is ", rand.Intn(10))
	fmt.Println(big.Above)
	fmt.Printf("Format %g is like this\n", math.Sqrt(91))

}

func add(a int, b int) int {
	return a + b
}

func swap(a, b string) (string, string) {
	return b, a
}

func mulladd(a, b int) (sum, mul int) {
	sum = a + b
	mul = a * b
	return
}

func Sqrt(x float64) (z float64) {
	for zn := float64(1); math.Abs(z-zn) > 0.0001; zn = z - (z*z-x)/(2*z) {
		z = zn
	}
	return
}

func WriteDay() {
	today := time.Now().Weekday()
	switch time.Saturday {
	case today + 0:
		fmt.Println("Today.")
	case today + 1:
		fmt.Println("Tomorrow.")
	case today + 2:
		fmt.Println("In two days.")
	default:
		fmt.Println("Too far away.")
	}
}

func main() {

	WriteDay()

	var (
		ToBo   bool       = true
		MaxInt uint64     = 1<<64 - 1
		z      complex128 = cmplx.Sqrt(-1 + 2i)
	)

	fmt.Println(runtime.GOOS, runtime.GOARCH, runtime.Compiler, runtime.NumCPU())
	fmt.Println(Sqrt(2), math.Sqrt(2))

	rand.Seed(42)

	x, y := swap("World", "Hello")

	fmt.Printf("X = %T and Y = %s\n", x, y)

	name()
	fmt.Println("Hello, Arch!", add(420, 246))
	fmt.Println(ToBo, MaxInt, z)

	for i := 0; i < 10; i++ {
		fmt.Println(i)
	}

	sum := 1
	for sum < 1000 {
		sum += sum
	}
	fmt.Println(sum)

}
