use std::fmt;


// Declare Foo and Bar structs
struct Foo {
    x: i32
}

struct Bar {
    x: i32,
    y: i32
}


// Implement fmt::Displat trait for them
impl fmt::Display for Foo {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "(x: {})", self.x)
    }
}

impl fmt::Display for Bar {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "(x: {}, y: {})", self.x, self.y)
    }
}

// Generic function that takes anything that has implemented
// fmt::Display trait
fn print_me<T: fmt::Display>(obj : T) {
    println!("Value: {}", obj);
}


fn main() {
    let foo = Foo {x: 7};
    let bar = Bar {x: 5, y: 10};
    print_me(foo);
    print_me(bar);
}
