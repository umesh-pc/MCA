const con = require('./conn');

const cr_Tb = `CREATE TABLE IF NOT EXISTS T_db.students (
    rollno INT PRIMARY KEY,
    name VARCHAR(15)
)`;
// Notice 'CREATE' is on the same line as the opening backtick

// Run the query
con.query(cr_Tb, (err) => {
    if (err) throw err;
    console.log('Table students created');
});