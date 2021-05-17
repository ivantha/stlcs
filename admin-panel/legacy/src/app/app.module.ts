import {NgModule} from '@angular/core';
import {BrowserModule} from '@angular/platform-browser';
import {BrowserAnimationsModule} from '@angular/platform-browser/animations';

import {AppRoutingModule} from './app-routing.module';
import {AppComponent} from './app.component';
import {DashboardComponent} from './components/dashboard/dashboard.component';
import {SignInComponent} from './components/sign-in/sign-in.component';
import {SidebarComponent} from './components/sidebar/sidebar.component';
import {HeaderComponent} from './components/header/header.component';
import {FooterComponent} from './components/footer/footer.component';

import {ButtonModule} from 'primeng/button';
import {PanelMenuModule} from 'primeng/panelmenu';
import { SimulatorComponent } from './components/simulator/simulator.component';

@NgModule({
    declarations: [
        AppComponent,
        DashboardComponent,
        SignInComponent,
        SidebarComponent,
        HeaderComponent,
        FooterComponent,
        SimulatorComponent,
    ],
    imports: [
        BrowserModule,
        BrowserAnimationsModule,
        AppRoutingModule,

        ButtonModule,
        PanelMenuModule,
    ],
    providers: [],
    bootstrap: [AppComponent]
})

export class AppModule {

}
