

// Here are some features of rust language got from official tutorial


fn is_four(x: i32) -> bool {
   // No need for a return statement. The result of the expression
   // is used as the return value.
   x == 4
}

fn bells_whistles(x: f64, y: f64) -> String {

   let var =  // Look here - a big bell and whistle
      if x == y {
         "woho"
      } else if x > y {
         "grater"
      } else {
         "smaller"
      }; // <<==== note semicolon here

   return var.to_string(); // can concatenate strings with +
}


/// WTF is tripple comment???

// Outsadi only statics are legal
static A_VAR: i32 = 34; // note explicit type here mandatory
//let s = "ss";

fn main()  // EP as always
{
   let s = "stringa" ; // this is a string variable

   loop {
      if is_four(4) {
         println!("Was indeed a four");
      }
      println!("Here is one \n{}\nAnd here is another\n{}\n and a {}", s, bells_whistles(49., 50.0f64), A_VAR); // HOW to printf?
      return;
   }
}
