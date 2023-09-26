const express = require("express");
const path = require("path");
const mongoose = require("mongoose");
const article = require("./models/article");
const bodyParser = require("body-parser");
const expressValidator = require("express-validator");
const flash = require("connect-flash");
const session = require("express-session");
const passport = require("passport");
const config = require("./config/database");

mongoose.connect(config.database);
let db = mongoose.connection;

//check connection
db.once("open", function () {
    console.log("Connected to mongodb");
});
//check for db errors
db.on("error", function () {
    console.log(err);
});

//init app
const app = express();

//bring in models
let Article = require("./models/article");

//load view engine
app.set("views", path.join(__dirname, "views"));
app.set("view engine", "pug");

//body parser middleware
app.use(bodyParser.urlencoded({ extended: false }));
//parse application

app.use(bodyParser.json());

//set public folder
app.use(express.static(path.join(__dirname, "public")));

//express session middleware
app.use(session({
    secret: "keyboard cat",
    resave: true,
    saveUninitialized: true,
}));

//express messages middleware
app.use(require("connect-flash")());
app.use(function (req, res, next) {
    res.locals.messages = require("express-messages")(req, res);
    next();
});

//express validator middleware
app.use(expressValidator({
    errorFormatter: function (param, msg, value) {
        var namespace = param.split('.'),
            root = namespace.shift(),
            formParam = root;

        while (namespace.lenght) {
            formParam += '[' + namespace.shift() + ']';
        }
        return {
            param: formParam,
            msg: msg,
            value: value
        };
    }
}));

//passport config
require("./config/passport")(passport);
//passport middleware
app.use(passport.initialize());
app.use(passport.session());


app.get("*", function(req, res, next){
    res.locals.user = req.user || null;
    next();
});
//home route
app.get("/", function (req, res) {


    // let articles = [
    //     {
    //         id:1,
    //         title: "Article One",
    //         author: "Vanshika",
    //         body: "This is article one",
    //     },
    //     {
    //         id:2,
    //         title: "Article Two",
    //         author: "Pushkar",
    //         body: "This is article two",
    //     },
    //     {
    //         id:3,
    //         title: "Article Three",
    //         author: "Poonam",
    //         body: "This is article three",
    //     }
    // ];

    Article.find({}, function (err, articles) {
        if (err) {
            console.log(err);
        }
        else {
            res.render("index", {
                title: "Articles",
                articles: articles
            });
        }
    });
});

//route files
let articles = require("./routes/articles");
let users = require("./routes/users");
app.use("/articles",articles);
app.use("/users",users);

//start server
app.listen(3000, function () {
    console.log("Server started on port 3000");
});