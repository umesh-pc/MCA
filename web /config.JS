const mysql = require('mysql');

const con = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: '123',
});

con.connect((err) => {
    if (err) {
        console.error('Error connecting:', err.stack);
        return;
    }
    console.log('Connected to MySQL server');

    con.query('CREATE DATABASE IF NOT EXISTS T_db', (err, result) => {
        if (err) throw err;
       
        con.end();
    });
});
module.exports=con;
