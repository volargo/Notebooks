-- syntax --
-- Mariadb [TABLES]> CREATE TABLE table_name (column_name column_type);

-- -----------------------------------
-- Create database
-- -----------------------------------
CREATE DATABASE PRODUCTS;

-- -----------------------------------
-- Create tables of products database
-- -----------------------------------
CREATE TABLE products_tbl(
    product_id INT NOT NULL AUTO_INCREMENT,
    product_name VARCHAR(100) NOT NULL,
    product_manufurturer VARCHAR(40) NOT NULL,
    submission_data DATE,
    PRIMARY KEY ( product_id )
);
