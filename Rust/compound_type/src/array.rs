fn main() {
    let months = ["January", "February","March", "April", "May",
                 "June", "July", "August", "September", "October",
                 "November", "December"];
    
    for month in 0..months.len() {
        println!("The {}. month is = {}", (month + 1), months[month]);
    }

}