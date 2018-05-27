angular.module('robotestapp', [])
    .controller('TestCtrl', ['$scope',
        function ($scope) {
            $scope.code = generateCode();
            $scope.inputCode = "";
            let counter = 1;

            $scope.appendNum = function (number) {
                let currentVal = $scope.inputCode;
                $scope.inputCode = currentVal + number;
                if (counter <= $scope.code.toString().length) {
                    console.log(counter);
                    if ($scope.code.toString() == $scope.inputCode) {
                        counter = 1;
                        $scope.inputCode = "";
                        alert("CORRECT input!");
                        $scope.code = generateCode();
                    } else if (counter == $scope.code.toString().length && $scope.code.toString() != $scope.inputCode) {
                        counter = 1;
                        $scope.inputCode = "";
                        alert("WRONG input!");
                        $scope.code = generateCode();
                    }
                    else {
                        counter++;
                    }
                }
            }

            $scope.reload = function () {
                $scope.code = generateCode();
            }

            function generateCode() {
                return Math.floor(Math.random() * 10000);
            }
        }]);