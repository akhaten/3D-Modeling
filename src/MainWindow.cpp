//
// Created by jessy on 28/04/2021.
//

#include "MainWindow.h"

#include <Gui/RaGui.hpp>
#include <Gui/Viewer/Viewer.hpp>
//#include <Gui/TreeModel/TreeModel.hpp>
#include <Gui/SelectionManager/SelectionManager.hpp>

#include <PluginBase/RadiumPluginInterface.hpp>

using namespace Ra::Gui;
using namespace Ra::Engine;
using namespace Ra::Engine::Rendering;
using namespace Ra::Engine::Scene;

MainWindow::MainWindow(QWidget *parent) : Ra::Gui::MainWindowInterface(parent) {

    //setupUi( this );

    // Initialize the minimum tools for a Radium-Guibased Application

    m_viewer = std::make_unique<Ra::Gui::Viewer>();
    m_viewer->setObjectName( QStringLiteral( "m_viewer" ) );

    // Initialize the scene interactive representation
    m_sceneModel       = new ItemModel( Ra::Engine::RadiumEngine::getInstance(), this );
    m_selectionManager = new SelectionManager( m_sceneModel, this );

    /*
     connect( m_selectionManager,
             &Ra::Gui::SelectionManager::selectionChanged,
             this,
             &MainWindow::onSelectionChanged );
     */

    // initialize Gui for the application
    auto viewerwidget = QWidget::createWindowContainer( m_viewer.get() );
    viewerwidget->setAutoFillBackground( false );
    setCentralWidget( viewerwidget );
    setWindowTitle( QString( "Billard3D" ) );


    //createConnections();
}

MainWindow::~MainWindow() = default;

Ra::Gui::Viewer *MainWindow::getViewer() {
    return m_viewer.get();
}

Ra::Gui::SelectionManager* MainWindow::getSelectionManager() {
    return m_selectionManager;
}

Ra::Gui::Timeline* MainWindow::getTimeline() {
    // mus return not null ?
    return m_timeline;
}

void MainWindow::updateUi( Ra::Plugins::RadiumPluginInterface* plugin ) {

}

void MainWindow::onFrameComplete() {}
void MainWindow::addRenderer(
        const std::string &name,
        std::shared_ptr<Ra::Engine::Rendering::Renderer> e) {

}

void MainWindow::addControl( const QString& tabName, const QKeySequence& shortcut ) {

}

void MainWindow::prepareDisplay() {
    if ( m_viewer->prepareDisplay() ) { emit frameUpdate(); }
}

void MainWindow::cleanup() {
    // Must ensure the viewer is deleted once.
    m_viewer.reset( nullptr );
}
