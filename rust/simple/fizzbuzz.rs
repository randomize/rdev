

use std::fmt::{Display, Error, Formatter};

enum FizzBuzzValue {
    Value(u64),
    Fizz(u64),
    Buzz(u64),
    FizzBuzz(u64),
}


impl Display for FizzBuzzValue {
    fn fmt(&self, f: &mut Formatter) -> Result<(), Error >  {
        match self {
            &FizzBuzzValue::FizzBuzz(_) => write!(f, "FizzBuzz"),
            &FizzBuzzValue::Buzz(_) => write!(f, "Buzz"),
            &FizzBuzzValue::Fizz(_) => write!(f, "Fizz"),
            &FizzBuzzValue::Value(n) => write!(f, "{}", n),
        }
    }
    
}

pub fn main() {

    for n in (1..101).map(to_fzbx) {
        println!("{}", n);
    }
    
}


fn to_fzbx(n: u64) -> FizzBuzzValue {

    match n {
        n if n % 15 == 0 => FizzBuzzValue::FizzBuzz(n),
        n if n %  5 == 0 => FizzBuzzValue::Fizz(n),
        n if n %  3 == 0 => FizzBuzzValue::Buzz(n),
        n => FizzBuzzValue::Value(n),
    }


}

