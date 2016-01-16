// vim: ft=rust

fn main() {

    let nums = [1, 2];
    let noms = ["Tim", "Eston", "Aaron", "Ben"];

    let mut odds = nums.iter().map(|&x| x * 2 - 1);
 
    for num in odds {
        println!("value is: {}", noms[num]);
    }
}
