$(document).ready(function() {
    $("#code-field").text(function() {
        let result = Math.floor(Math.random() * 10000);
        return "Code to Input: " + result;
    });
    $("#btn-0").click(function() {
        numAppend(0);
    });
    $("#btn-1").click(function() {
        numAppend(1);
    });
    $("#btn-2").click(function() {
        numAppend(2);
    });
    $("#btn-3").click(function() {
        numAppend(3);
    });
    $("#btn-4").click(function() {
        numAppend(4);
    });
    $("#btn-5").click(function() {
        numAppend(5);
    });
    $("#btn-6").click(function() {
        numAppend(6);
    });
    $("#btn-7").click(function() {
        numAppend(7);
    });
    $("#btn-8").click(function() {
        numAppend(8);
    });
    $("#btn-9").click(function() {
        numAppend(9);
    });
});

function numAppend(value) {
    let currentVal = $("#main-input").val();
    currentVal += value;
    $("#main-input").val(currentVal);
}