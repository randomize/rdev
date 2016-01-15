

// Rust test program

fn main() {

    let mut x = vec!["Hello", "world"];

    let y = x[0].clone();

    {
        let y = &x[0];
    }

    x.push("foo");

    // println!(y);
}
