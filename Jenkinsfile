pipeline {
    agent any
    stages {
        stage('Restore') {
            steps {
                bat 'chcp 65001 && "C:\\Program Files\\Microsoft Visual Studio\\18\\Community\\MSBuild\\Current\\Bin\\MSBuild.exe" Sample-lab4\\Sample-lab4.vcxproj -t:restore'
            }
        }
        stage('Build') {
            steps {
                bat 'chcp 65001 && "C:\\Program Files\\Microsoft Visual Studio\\18\\Community\\MSBuild\\Current\\Bin\\MSBuild.exe" Sample-lab4.slnx /t:Rebuild /p:Configuration=Debug'
            }
        }
        stage('Test') {
            steps {
                bat 'chcp 65001 && "x64\\Debug\\Sample-lab4.exe" --gtest_output=xml:test_report.xml'
            }
        }
    }
    post {
        always {
            junit 'test_report.xml'
        }
    }
}
