const express = require("express");
const router = express.Router();


//bring in models
//article model
let Article = require("../models/article");
//user model
let User = require("../models/user");


//add route
router.get("/add", ensureAuthenticated, function (req, res) {
    res.render("add_article", {
        title: "Add Article"
    });
});

// router.get("/add", function (req, res) {
//     res.render("add_article", {
//         title: "Add Article"
//     });
// })

//add submit POST route
router.post("/add", function (req, res) {
    // console.log("Submitted");
    // return;

    //rules for empty field
    req.checkBody("title", "Title is required!").notEmpty();
    //req.checkBody("author", "Author is required!").notEmpty();
    req.checkBody("body", "Body is required!").notEmpty();

    //get errors
    let errors = req.validationErrors();
    if (errors) {
        res.render("add_article", {
            title: "Add Article",
            errors: errors
        });
    }
    else {
        let article = new Article();
        article.title = req.body.title;
        // article.author = req.body.author;
        article.author = req.user._id;
        article.body = req.body.body;

        article.save(function (err) {
            if (err) {
                console.log(err);
                return;
            }
            else {
                req.flash("success", "Article Added, Successfully!");
                res.redirect("/");
            }
        });
    }
    // let article = new Article();
    // article.title = req.body.title;
    // article.author = req.body.author;
    // article.body = req.body.body;

    // article.save(function(err){
    //     if(err){
    //         console.log(err);
    //         return;
    //     }
    //     else{
    //         req.flash("success", "Article Added, Successfully!");
    //         res.redirect("/");
    //     }
    // });

    // console.log(req.body.title);
    // return;
});

//load edit form
router.get("/edit/:id",ensureAuthenticated,function (req, res) {
    Article.findById(req.params.id, function (err, article) {
        // console.log(article);
        // return;
        if(article.author!=req.user._id){
            req.flash("danger","Not Authorized");
            res.redirect("/");
        }
        res.render("edit_article", {
            title: "Edit Article",
            article: article
        });
    });
});

//update submit POST route
router.post("/edit/:id", function (req, res) {
    // console.log("Submitted");
    // return;

    let article = {};
    article.title = req.body.title;
    article.author = req.body.author;
    article.body = req.body.body;

    let query = { _id: req.params.id }
    Article.update(query, article, function (err) {
        if (err) {
            console.log(err);
            return;
        }
        else {
            req.flash("success", "Article Updated!")
            res.redirect("/");
        }
    });
    // console.log(req.body.title);
    // return;
});

router.delete("/:id", function (req, res) {
    if(!req.user._id){
        res.status(500).send();
    }
    let query = { _id: req.params.id }
    Article.findById(req.params.id, function(err, article){
        if(article.author!= req.user._id){
            res.status(500).send();
        }
        else{
            Article.remove(query, function (err) {
                if (err) {
                    console.log(err);
                }
                res.send("Success");
            });
        }
    });
    // Article.remove(query, function (err) {
    //     if (err) {
    //         console.log(err);
    //     }
    //     res.send("Success");
    // });
});

//get single article
router.get("/:id", function (req, res) {
    Article.findById(req.params.id, function (err, article) {
        User.findById(article.author, function (err, user) {
            res.render("article", {
                article: article,
                author: user.name
            });
        });
        // console.log(article);
        // return;
    });
});

//access control
// function ensureAuthenticated(req, res, next) {
//     if (req.isAuthenticated()) {
//         //req.isAuthenticated() will return true if user is logged in
//         return next();
//     } else {
//         req.flash("danger", "Please login.");
//         res.redirect("/users/login");
//     }
// };

function ensureAuthenticated(req, res, next) {
    if (req.isAuthenticated()) {
        return next();
    }
    else {
        req.flash("danger", "Please login.");
        res.redirect("/users/login");
    }
}
module.exports = router;
